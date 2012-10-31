<?php
/**
 * Implementation of THEMEHOOK_settings() function.
 *
 * @param $saved_settings
 *   array An array of saved settings for this theme.
 * @return
 *   array A form array.
 */
function unimelb_form_system_theme_settings_alter(&$form, $form_state) {

  // Flatten form.
  $form['#tree'] = FALSE;

  $form['unimelb'] = array(
    '#type' => 'fieldset',
    '#title' => t('UniMelb Settings'),
    '#description' => t('Settings specific to the University of Melbourne theme.'),
  );

  $version = theme_get_setting('unimelb_settings_template');
  // Create the settings form.
  $form['unimelb']['unimelb_settings_template'] = array(
    '#type' => 'select',
    '#title' => t('Web Templates Version'),
    '#description' => t('Choose the version of the MARCOM web templates you want to use.'),
    '#options' => array(
      '1-1-0' => t('Version 1.1.0'),
      '1-2-0-ALPHA' => t('Version 1.2.0 alpha'),
    ),
    '#default_value' => empty($version) ? '1-1-0' : $version,
  );

  $columns = theme_get_setting('unimelb_settings_columns');
  if (empty($columns)) {
    $columns = '3-1';
  }
  $form['unimelb']['unimelb_settings_columns'] = array(
    '#type' => 'select',
    '#title' => t('Column Grid'),
    '#description' => t('Choose the column layout for the front page.'),
    '#options' => array(
      '2-1' => t('2-2-2-2+1 - Two responsive in the main content, one fixed in navigation.'),
      '3-1' => t('3-3-3-3+1 - Three responsive in the main content, one fixed in navigation.'),
      '6-1' => t('6-3-3+1 - Six plus three responsive in the main content, one fixed in navigation.'),
      '4-2' => t('4-2-4-2 - Four plus two responsive in the main content, no navigation.'),
      '4-4' => t('4-4-4-4 - Four plus four responsive in the main content, no navigation.'),
      '8-4' => t('8-4 - Eight plus four responsive in the main content, no navigation.'),
    ),
    '#default_value' => $columns,
    '#required' => TRUE,
  );

  $form['unimelb']['unimelb_settings_custom_logo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Custom Logo'),
    '#description' => t('If you do not want to use the logo provider by the brand.unimelb.edu.au injector, check this box. You will need to use your theme\'s logo or include some custom CSS.'),
    '#default_value' => theme_get_setting('unimelb_settings_custom_logo'),
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_site_search_box'] = array(
    '#type' => 'checkbox',
    '#title' => t('Site search box'),
    '#description' => t('Display a site search box'),
    '#default_value' => theme_get_setting('unimelb_settings_site_search_box'),
    '#required' => false,
  );

  $form['unimelb']['unimelb_settings_parent-org'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent organisational unit (optional)'),
    '#description' => t('The parent organisational unit appears on the home page above the site name'),
    '#default_value' => theme_get_setting('unimelb_settings_parent-org'),
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_parent-org-url'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent organisational unit URL (optional)'),
    '#description' => t('eg. http://www.unimelb.edu.au'),
    '#default_value' => theme_get_setting('unimelb_settings_parent-org-url'),
    '#size' => 60,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ht-left'] = array(
    '#type' => 'textfield',
    '#title' => t('Headingtext left (optional)'),
    '#description' => t('The headingtext appears on the home page below the site name. The left portion is a very short phrase providing context for the right portion, eg. "Who we are"'),
    '#default_value' => theme_get_setting('unimelb_settings_ht-left'),
    '#size' => 40,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ht-right'] = array(
    '#type' => 'textfield',
    '#title' => t('Headingtext right (optional)'),
    '#description' => t('The right portion of the headingtext is a succinct statement describing the web site'),
    '#default_value' => theme_get_setting('unimelb_settings_ht-right'),
    '#size' => 120,
    '#maxlength' => 1024,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_meta-keywords'] = array(
    '#type' => 'textfield',
    '#title' => t('Meta keywords (optional)'),
    '#description' => t('Comma-separated list of keywords for use in meta tags'),
    '#default_value' => theme_get_setting('unimelb_settings_meta-keywords'),
    '#size' => 120,
    '#maxlength' => 1024,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-line1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Line 1 (optional)'),
    '#description' => t('eg. Level 1, Raymond Priestly Building'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-line1'),
    '#size' => 60,
    '#maxlength' => 512,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-line2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Line 2 (optional)'),
    '#description' => t('eg. University of Melbourne'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-line2'),
    '#size' => 60,
    '#maxlength' => 512,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-sub'] = array(
    '#type' => 'textfield',
    '#title' => t('City or suburb (optional)'),
    '#description' => t('eg. Parkville'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-sub'),
    '#size' => 40,
    '#maxlength' => 512,
    '#required' => FALSE,
  ); 

  $form['unimelb']['unimelb_settings_ad-postcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postcode (optional)'),
    '#description' => t('eg. 3010'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-postcode'),
    '#size' => 20,
    '#maxlength' => 10,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-state'] = array(
    '#type' => 'textfield',
    '#title' => t('State or territory (optional)'),
    '#description' => t('eg. VIC'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-state'),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => FALSE,
  ); 

  $form['unimelb']['unimelb_settings_ad-country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country (optional)'),
    '#description' => t('eg. Australia'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-country'),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone (required)'),
    '#description' => t('eg. +61 3 8344 1670'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-phone'),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax (optional)'),
    '#description' => t('eg. +61 3 8344 1670'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-fax'),
    '#size' => 20,
    '#maxlength' => 64,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_ad-email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email (required)'),
    '#description' => t('Email address for general enquiries, eg. example@unimelb.edu.au'),
    '#default_value' => theme_get_setting('unimelb_settings_ad-email'),
    '#size' => 40,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_fb-url'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook URL (optional)'),
    '#description' => t('eg. http://www.facebook.com/melbuni'),
    '#default_value' => theme_get_setting('unimelb_settings_fb-url'),
    '#size' => 60,
    '#maxlength' => 1024,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_tw-url'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter (optional)'),
    '#description' => t('eg. http://www.facebook.com/unimelb'),
    '#default_value' => theme_get_setting('unimelb_settings_tw-url'),
    '#size' => 60,
    '#maxlength' => 1024,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_wordpress-url'] = array(
    '#type' => 'textfield',
    '#title' => t('Wordpress (optional)'),
    '#description' => t('eg. Your wordpress url'),
    '#default_value' => theme_get_setting('unimelb_settings_wordpress-url'),
    '#size' => 60,
    '#maxlength' => 1024,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_auth-name'] = array(
    '#type' => 'textfield',
    '#title' => t('Authoriser Name and or Position (required)'),
    '#description' => t('eg. Jane Smith, Faculty of Bar'),
    '#default_value' => theme_get_setting('unimelb_settings_auth-name'),
    '#size' => 80,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_maint-name'] = array(
    '#type' => 'textfield',
    '#title' => t('Maintainer Name and or Position (required)'),
    '#description' => t('eg. Pat Doe, Faculty of Bar'),
    '#default_value' => theme_get_setting('unimelb_settings_maint-name'),
    '#size' => 80,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  $form['unimelb']['unimelb_settings_date-created'] = array(
    '#type' => 'textfield',
    '#title' => t('Date created (optional)'),
    '#description' => t('The date the site was launched, eg. 11 February 2010'),
    '#default_value' => theme_get_setting('unimelb_settings_date-created'),
    '#size' => 20,
    '#maxlength' => 256,
    '#required' => FALSE,
  );

  return $form;
}
