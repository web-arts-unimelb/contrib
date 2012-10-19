<?php

// thanks to Aaron Tan and team at the Faculty of Architecture, Building and Planning, University of Melbourne, and Paul Tagell and team at Marketing and Communications, University of Melbourne - Media Insights 2011

/*
 * generic variables:
 * $attributes_array
 * $title_attributes_array
 * $content_attributes_array
 * $classes_array
 *  Array of html class attribute values. It is flattened into a string within the variable $classes. 
 * $title_prefix
 *  An array containing additional output populated by modules, intended to be displayed in front of the main title tag that appears in the template.
 * $title_suffix
 *  An array containing additional output populated by modules, intended to be displayed after the main title tag that appears in the template.
 * $id
 *  The placement of the template. Each time the template is used, it is incremented by one.
 * $zebra
 *  Either "odd" or "even". Alternate each time the template is used.
 * $directory
 *  The theme path relative to the base install. example: "sites/all/themes/myTheme"
 * $is_admin
 *  Boolean returns TRUE when the visitor is a site administrator.
 * $is_front
 *  Boolean returns TRUE when viewing the front page of the site.
 * $logged_in
 *  Boolean returns TRUE when the visitor is a member of the site, logged in and authenticated.
 * $db_is_active
 *  Boolean returns TRUE when the database is active and running. This is only useful for theming in maintenance mode where the site may run into database problems.
 * $user
 *  The user object containing data for the current visitor. Some of the data contained here may not be safe. Be sure to pass potentially dangerous strings through check_plain.
 *  
 * Regions:
 *  regions[newsbanner]	= Newsbanner
 *  regions[help]		= Help
 *  regions[content]	= Content
 *  regions[navigation]	= Navigation
 *  regions[column1]	= Column 1
 *  regions[column2]	= Column 2
 *  regions[column3]	= Column 3
 *  regions[column4]	= Column 4
 * 
*/


?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>

<?php print $head; ?>

<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />

<title><?php print $site_name . ' | ' . $page_title; ?></title>

<!-- SEO relevant meta data to describe content of page -->
	<meta name="DC.Title" content="<?php print $site_name . ' | ' . $page_title; ?>" />
	<meta name="keywords" content="<?php print $unimelb_meta_keywords; ?>" />
	<meta name="description" content="<?php print $unimelb_meta_description; ?>" />
	<meta name="DC.Description" content="<?php print $unimelb_meta_description; ?>" />
<!-- End SEO relevant meta data -->

<!-- Authoriser and maintainer related meta data - developers, don't forget humans.txt -->
	<meta name="DC.Creator" content="<?php print $unimelb_meta_creator; ?>" />
	<meta name="DC.Contributor" content="<?php print $unimelb_meta_creator; ?>" />
	<meta name="author" content="<?php print $unimelb_meta_creator; ?>" />
	<meta name="UM.Authoriser.Name" content="<?php print $unimelb_meta_authoriser; ?>" />
	<meta name="UM.Authoriser.Title" content="<?php print $unimelb_meta_authoriser; ?>" />
	<meta name="UM.Maintainer.Name" content="<?php print $unimelb_meta_creator; ?>" />
	<meta name="UM.Maintainer.Department" content="<?php print $unimelb_meta_creator; ?>" />
	<meta name="UM.Maintainer.Email" content="<?php print $unimelb_meta_email; ?>" />
<!-- End authoriser and maintainer meta data -->

<!-- Static meta data   -->
	<meta name="DC.Rights" content="http://www.unimelb.edu.au/disclaimer" />
	<meta name="DC.Publisher" content="The University of Melbourne" />
	<meta name="DC.Format" content="text/html" />
	<meta name="DC.Language" content="en" />
	<meta name="DC.Identifier" content="http://www.unimelb.edu.au/" />
<!-- End static meta data -->

<!-- Meta data to be autofilled -->
	<meta name="DC.Date" content="<?php print $unimelb_meta_date; ?>" />
	<meta name="DC.Date.Modified" content="<?php print $unimelb_meta_date; ?>" />
<!-- End meta data to be autofilled -->

	<meta content="width=device-width; initial-scale=0.67;" name="viewport" />

  <!-- BASE STYLES -->
  <?php print $styles_system; ?>
  <?php print $styles_default; ?>
  <!-- /BASE STYLES -->

  <!-- GLOBAL RESOURCES -->
  <!-- DO NOT CHANGE -->
  <link rel="stylesheet" href="<?php print $scheme; ?>brand.unimelb.edu.au/web-templates/<?php print $version; ?>/css/complete.css" />
<script type="text/javascript" src="<?php print $scheme; ?>brand.unimelb.edu.au/web-templates/<?php print $version; ?>/js/complete.js"></script>

<!-- Not sure that this works the right way around. Investigate -->
<?php if (empty($overlay)) { ?>
  <link rel="stylesheet" href="<?php print $scheme; ?>brand.unimelb.edu.au/global-header/css/style.css" />
  <script type="text/javascript" src="<?php print $scheme; ?>brand.unimelb.edu.au/global-header/js/injection.js"></script>
<?php } ?>
  <!-- /GLOBAL RESOURCES -->

  <!-- THEME STYLES -->
  <?php print $styles_theme; ?>
  <!-- /THEME STYLES -->

<!--[if lt IE 9]>
	<script type="text/javascript" src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->

<?php print $scripts; ?>

</head>

<body class="<?php print $brand_logo; ?><?php if($is_front) { print ' home '; } else { print ' blue '; } ?> <?php print $classes; ?>" <?php if($attributes) { print ' ' . $attributes; } ?>>

<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>

</body>

</html>
