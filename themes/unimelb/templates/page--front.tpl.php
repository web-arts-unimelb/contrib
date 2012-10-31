<?php
// thanks to Aaron Tan and team at the Faculty of Architecture, Building and
// Planning, University of Melbourne, and Paul Tagell and team at Marketing
// and Communications, University of Melbourne - Media Insights 2011.

/**
 * @file
 * theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system folder.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * 
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 */
?>

<div class="wrapper">
  <div class="header <?php if(!empty($unimelb_ht_right) && $is_front) { ?>with-ht<?php } else { ?>without-ht<?php } ?>">

  <div class="hgroup">
    <?php if ($brand_logo == 'logo' && !empty($logo)): ?>
      <a href="<?php print $front_page; ?>" title="Home" rel="home"><img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" /></a>
    <?php else: ?>

    <?php
      if(!empty($unimelb_meta_parent_org_url))
        $home_page_url = $unimelb_meta_parent_org_url;
      else
        $home_page_url = $front_page;
    ?>

    <?php if(!empty($unimelb_meta_parent_org)): ?>
      <p><a href="<?php echo $home_page_url ?>"><?php echo $unimelb_meta_parent_org ?></a></p>
    <?php endif; ?>

      <h1><a href="<?php print $front_page; ?>" title="Home" rel="home"><?php print $site_name; ?></a></h1>
    <?php endif; ?>
  </div><!-- end hgroup -->

  <?php if (!empty($unimelb_ht_right) && $is_front): ?>
    <div id="headingtext">
        <p class="title col-1"><?php print $unimelb_ht_left; ?></p>
        <p class="col-7"><?php print $unimelb_ht_right; ?></p>
        <hr />
      </div>
  <?php endif; ?>

  </div><!-- end header -->

  <?php if (!empty($messages)): ?>
    <div class="col-8" role="complementary">
        <?php print $messages; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['feature_menu'])): ?>
    <div class="feature col-8">
      <div id="feature-menu" class="col-6">
        <?php print render($page['feature_menu']); ?>
        <?php if (function_exists('social_icons')): echo social_icons(); endif; ?>
      </div>

      <?php if(!empty($site_search_box)): ?>
        <div id="site-search" class="col-2">
          <a id="search-button" href="#">Search</a><input id="search-input"/>
        </div>
      <?php endif;?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['slider'])): ?>
    <div class="col-8" role="complementary" id="slider">
      <?php print render($page['slider']); ?>
    </div>
  <?php endif; ?>

  <!-- Include a layout-specific template file on the front page. -->
  <?php include($variables['layout']); ?>

</div><!-- end wrapper -->

<hr /><div class="footer"><div id="local" class="wrapper">
  <p class="footertitle"><?php print _unimelb_space_tags($site_name); ?></p>

      <?php if(!empty($unimelb_ad_line1) || !empty($unimelb_ad_line2)): ?>
        <div id="org-details" class="col-2">
          <?php if(!empty($unimelb_parent_org)): ?>
            <p><strong><?php print $unimelb_parent_org; ?></strong></p>
          <?php endif; ?>
          <p class="location">
          <?php if(!empty($unimelb_ad_line1)): ?><?php print $unimelb_ad_line1; ?><br /><?php endif; ?>
          <?php if(!empty($unimelb_ad_line2)): ?><?php print $unimelb_ad_line2; ?><br /><?php endif; ?>
          <?php print $unimelb_ad_sub; ?>&nbsp;<?php print $unimelb_ad_postcode; ?>&nbsp;<?php print $unimelb_ad_state; ?>&nbsp;<?php print $unimelb_ad_country; ?></p>
        </div>
      <?php endif; ?>


      <?php if(!empty($unimelb_meta_email)): ?>
        <ul class="col-2">
          <li>
            <strong>Email: </strong> 
            <a href="mailto:<?php print $unimelb_meta_email; ?>"><?php print $unimelb_meta_email; ?></a>
          </li>

          <?php if(!empty($unimelb_meta_phone)): ?>
          <li>
            <strong>Phone:</strong> <?php print $unimelb_meta_phone; ?>
         </li>
         <?php endif; ?>


         <?php if(!empty($unimelb_meta_fax)): ?>
           <li>
             <strong>Fax:</strong> <?php print $unimelb_meta_fax; ?>
           </li>
        <?php endif; ?>


        <?php if(!empty($unimelb_meta_facebook) || !empty($unimelb_meta_twitter)): ?>
          <li class="social">
            <?php if(!empty($unimelb_meta_facebook)): ?>
            <a class="facebook" href="<?php print $unimelb_meta_facebook; ?>">Facebook</a>
            &nbsp;
          <?php endif; ?>
          <?php if(!empty($unimelb_meta_twitter)): ?>
            <a class="twitter" href="<?php print $unimelb_meta_twitter; ?>">Twitter</a>
          <?php endif; ?>
        </li>
      <?php endif; ?>
    </ul>

<?php endif; ?>

<?php if(!empty($unimelb_meta_auth_name) || !empty($unimelb_meta_maint_name)): ?>
  <ul class="col-2">
    <?php if(!empty($unimelb_meta_auth_name)): ?>  
      <li>
        <strong>Authoriser:</strong><br />
        <?php print $unimelb_meta_auth_name; ?>
      </li>
    <?php endif; ?>

    <?php if(!empty($unimelb_meta_maint_name)): ?>  
      <li>
        <strong>Maintainer:</strong><br />
        <?php print $unimelb_meta_maint_name; ?>
      </li>
    <?php endif; ?>
  </ul>
<?php endif; ?>

<ul class="col-2">
  <?php if(!empty($unimelb_meta_date_created)): ?>
    <li>
      <strong>Date created:</strong><br />
      <?php print $unimelb_meta_date_created; ?>
    </li>
  <?php endif; ?>
  <li>
    <strong>Last modified:</strong><br />
    <?php print date('j F Y'); ?>
  </li>
</ul>

<hr /></div></div><!-- end footer -->
