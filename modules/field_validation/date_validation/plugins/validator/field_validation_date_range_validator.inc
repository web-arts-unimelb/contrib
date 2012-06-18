<?php
/**
 * @file
 * Field validation date range validator.
 *
 */
$plugin = array(
  'label' => t('Date range'),
  'description' => t("Validates user-entered text against a specified date range.For example: '{global}[2012-02-10 08:30:00, 2012-02-13 20:30:00]', '{year}(02-10 08:30:00, 02-13 20:30:00]', '{month}(07 08:30:00, 13 20:30:00)', '{week}(1 08:30:00, 5 20:30:00)', '{day}[08:30:00, 20:30:00)', '{hour}[10:00, 35:00]', '{minute}[00, 35]', '{global}[now, +1 month]'."),
  'handler' => array(
    'class' => 'field_validation_date_range_validator',
  ),
);

class field_validation_date_range_validator extends field_validation_validator {

  /**
   * Validate field. 
   */
  public function validate() {
    $date_range = $this->date_range_check_data($this->rule->settings['data']);
    $unit = isset($date_range['unit']) ? $date_range['unit'] : 'global';
    $start = isset($date_range['start']) ? $date_range['start'] : '';
    $end = isset($date_range['end']) ? $date_range['end'] : '';
    $start_contain = isset($date_range['start_contain']) ? $date_range['start_contain'] : TRUE;
    $end_contain = isset($date_range['end_contain']) ? $date_range['end_contain'] : TRUE;
    $less = isset($date_range['less']) ? $date_range['less'] : FALSE;

    $flag = FALSE;
    $data = $this->value;
    if ($data != '' ) {
      // support date, datetime
      if (!is_numeric($data)) {
        $data = strtotime($data);
      }

      $date_str = date("Y-m-d H:i:s", $data);

      if ($unit =='year') {
        $date_str = substr($date_str, 5);
      }
      elseif ($unit =='month') {
        $date_str = substr($date_str, 8);
      }
      elseif ($unit =='week') {
        $date_str = substr($date_str, 10);
        $week_day = date('w', strtotime($date_str));
        $date_str = $week_day . $date_str;
      }
      elseif ($unit =='day') {
        $date_str = substr($date_str, 11);
      }
      elseif ($unit =='hour') {
        $date_str = substr($date_str, 14);
      }
      elseif ($unit =='minute') {
        $date_str = substr($date_str, 17);
      }

      if ($date_str < $start) {
        $flag = TRUE;
      }
      if ($date_str > $end) {
        $flag = TRUE;
      }
      if (!$start_contain && $date_str == $start) {
        $flag = TRUE;
      }
      if (!$end_contain && $date_str == $end) {
        $flag = TRUE;
      }
      if ($less) {
        $flag = $flag ? FALSE : TRUE;
      }

      if ($flag) {
        $this->set_error();
      }
    } 
  }
  
  /**
   * Provide settings option
   */
  function settings_form(&$form, &$form_state) {
    $default_settings = $this->get_default_settings($form, $form_state);
    //print debug($default_settings);
    $form['settings']['data'] = array(
      '#title' => t('Date range'),
      '#description' => t("For example: '{global}[2012-02-10 08:30:00, 2012-02-13 20:30:00]', '{year}(02-10 08:30:00, 02-13 20:30:00]', '{month}(07 08:30:00, 13 20:30:00)', '{week}(1 08:30:00, 5 20:30:00)', '{day}[08:30:00, 20:30:00)', '{hour}[10:00, 35:00]', '{minute}[00, 35]', '{global}[now, +1 month]'."),
      '#type' => 'textfield',
      '#default_value' => isset($default_settings['data']) ? $default_settings['data'] : '',
    );
    parent::settings_form($form, $form_state);
  }
  
  function date_range_check_data($data) {
    $date_range = array(
      'unit' => 'global',
      'start_contain' => TRUE,
      'start' => '',
      'end' => '',
      'end_contain' => TRUE,
      'less' => FALSE,
    );
    // if no value was specified, don't validate
    if ($data == '') {
      return $date_range;
    }

    if (strpos($data, '}') !== FALSE) {
      list($first, $second) = explode('}', $data);
      //remove space
      $first = trim($first);
      //remove "{"
      $first = substr($first, 1);
      $date_range['unit'] = trim($first); 

      list($start_raw, $end_raw) = explode(',', $second);

      //remove space
      $start_raw = trim($start_raw);
      $end_raw = trim($end_raw);

      $start_contain = substr($start_raw, 0, 1);
      if ($start_contain =='[') {
        $date_range['start_contain'] = TRUE;
      }
      elseif ($start_contain =='(') {
        $date_range['start_contain'] = FALSE;
      }

      $start = substr($start_raw, 1);
      $date_range['start'] = trim($start);

      $end = substr($end_raw, 0, strlen($end_raw)-1);

      $date_range['end'] = trim($end);

      $end_contain = substr($end_raw, strlen($end_raw)-1, 1);

      if ($end_contain ==']') {
        $date_range['end_contain'] = TRUE;
      }
      elseif ($end_contain ==')') {
        $date_range['end_contain'] = FALSE;
      }

      //support php date format when unit = 'global'
      if ($date_range['unit'] == 'global') {
        //Support token value and value2, for example "{global}[value + 1 day, value + 6 month]".
        $value = isset($this->item['value']) ? $this->item['value'] : '';
        $value2 = isset($this->item['value2']) ? $this->item['value2'] : '';
        // support date, datetime
        if (!is_numeric($value)) {
          $value = strtotime($value);
        }

        $value = date("Y-m-d H:i:s", $value);

        // support date, datetime
        if (!is_numeric($value2)) {
          $value2 = strtotime($value2);
        }

        $value2 = date("Y-m-d H:i:s", $value2);
        $tokens = array(
          'value' => $value,
          'value2' => $value2,
        );
        $date_range['start'] = strtr($date_range['start'], $tokens);
        $date_range['end'] = strtr($date_range['end'], $tokens);

        $date_range['start'] = strtotime($date_range['start']);
        $date_range['start'] = date("Y-m-d H:i:s", $date_range['start']);

        $date_range['end'] = strtotime($date_range['end']);
        $date_range['end'] = date("Y-m-d H:i:s", $date_range['end']);
      }

      //if end less than start, reverse;
      //then we could support: {year}(10-10 08:30:00, 02-13 20:30:00]
      if ($date_range['end'] < $date_range['start']) {
        $date_range['less'] = TRUE;

        $start = $date_range['start'];
        $start_contain = $date_range['start_contain'];

        $date_range['start'] = $date_range['end'];
        $date_range['end'] = $start;

        $date_range['start_contain'] = $date_range['end_contain'] ? FALSE : TRUE;
        $date_range['end_contain'] = $start_contain ? FALSE : TRUE;
      }
    }
    return $date_range;
  }

}