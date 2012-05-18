<?php

// thanks to Aaron Tan and team at the Faculty of Architecture, Building and Planning, University of Melbourne, and Paul Tagell and team at Marketing and Communications, University of Melbourne - Media Insights 2011



/* start css */
drupal_add_css('http://brand.unimelb.edu.au/web-templates/1-2-0beta1/css/complete.css', array('group' => CSS_THEME, 'type' => 'external'));
drupal_add_css('/drupal/1-1-0/css/unimelb_drupal_distro.css', array('group' => CSS_THEME, 'type' => 'external'));
drupal_add_css('/drupal/1-1-0/css/custom.css', array('group' => CSS_THEME, 'type' => 'external'));
/* end css */


/* start js */
drupal_add_js('http://brand.unimelb.edu.au/global-header/js/injection.js', 'external');
// drupal_add_js('http://brand.unimelb.edu.au/web-templates/1-1-0/js/navigation.js', 'external');
// drupal_add_js('http://brand.unimelb.edu.au/web-templates/1-1-0/js/widgets.js', 'external');

drupal_add_js('/drupal/1-1-0/js/unimelb_drupal_distro.js', 'external');
//drupal_add_js('/drupal/1-1-0/js/newsbanner.js', 'external');
/* end js */


/**
 * making Unimelb Settings variables available to js
 */

if(variable_get('unimelb_settings_site-name-short') && variable_get('unimelb_settings_site-name-short', '') != ''){
$site_name = variable_get('unimelb_settings_site-name-short');
$vars1 = array('sitename' => $site_name);
drupal_add_js($vars1, 'setting');
}

if(variable_get('unimelb_settings_parent-org-short') && variable_get('unimelb_settings_parent-org-short', '') != ''){
$parent_org = variable_get('unimelb_settings_parent-org-short');
$vars2 = array('parentorg' => $parent_org);
drupal_add_js($vars2, 'setting');
}

if(variable_get('unimelb_settings_parent-org-url') && variable_get('unimelb_settings_parent-org-url', '') != ''){
$parent_orgurl = variable_get('unimelb_settings_parent-org-url');
$vars3 = array('parentorgurl' => $parent_orgurl);
drupal_add_js($vars3, 'setting');
}


// Define your functions here
function __is_page_highlight_defined(&$node)
{
	$highlight_node = field_get_items('node', $node, 'field_page_highlight');
	if ($highlight_node != FALSE) 
	{
		$highlight = $highlight_node[0]['value'];

	}
	else 
	{
		$highlight = "";
	}

	return $highlight;
}

function __redirect_by_external_url_field($node=null)
{
	$url = field_get_items('node', $node, 'field_external_url');
	$url_value = field_view_value('node', $node, 'field_external_url', $url[0], array());
	$url_markup = $url_value["#markup"];		

	if(empty($url_markup))
	{
		// Do nothing
	}
	else
	{
		// Need to validate url
		header("Location: $url_markup");
		die;	
	}
}
