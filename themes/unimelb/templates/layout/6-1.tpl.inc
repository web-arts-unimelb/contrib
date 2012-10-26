<?php
/**
 * @file
 * Layout-specific regions!
 *
 * 4   - Four responsive in the main content, no navigation.
 * 3-1 - Three responsive in the main content, one fixed in navigation.
 * 2-1 - Two responsive in the main content, one fixed in navigation.
 * 4-2 - Four plus two responsive in the main content, no navigation.
 * 4-4 - Four plus four responsive in the main content, no navigation.
 * 8-4 - Eight plus four responsive in the main content, no navigation.
 * 6-1 - Six plus three responsive in the main content, one fixed in navigation.
 */
?>


<div class="main col-6" role="main" id="main-content">
  <div class="col-6 first">
    <div class="col-1 first page-preview">
      <?php if(!empty($page['home_column_1'])): print render($page['home_column_1']); endif; ?>
    </div>

    <div class="col-1 page-preview">
      <?php if(!empty($page['home_column_2'])): print render($page['home_column_2']); endif; ?>
    </div>

    <div class="col-1 page-preview">
      <?php if(!empty($page['home_column_3'])): print render($page['home_column_3']); endif; ?>
    </div>

    <div class="col-1 page-preview">
      <?php if(!empty($page['home_column_4'])): print render($page['home_column_4']); endif; ?>
    </div>

    <div class="col-1 page-preview">
      <?php if(!empty($page['home_column_5'])): print render($page['home_column_5']); endif; ?>
    </div>

    <div class="col-1 page-preview">
      <?php if(!empty($page['home_column_6'])): print render($page['home_column_6']); endif; ?>
    </div>
  </div>

  <div class="col-6 first">
    <div class="col-2 first page-preview">
      <?php if(!empty($page['home_column_7'])): print render($page['home_column_7']); endif; ?>
    </div>

    <div class="col-2 page-preview">
      <?php if(!empty($page['home_column_8'])): print render($page['home_column_8']); endif; ?>
    </div>

    <div class="col-2 page-preview">
      <?php if(!empty($page['home_column_9'])): print render($page['home_column_9']); endif; ?>
    </div>
  </div>
</div>

<div class="col-2 rightside">
  <div class="aside" role="complementary">
    <?php if(!empty($page['navigation'])): print render($page['navigation']); endif; ?>

    <?php if(!empty($page['home_event'])): print render($page['home_event']); endif; ?>

    <?php if(!empty($page['home_promo'])): print render($page['home_promo']); endif; ?>

    <?php if(!empty($page['sidebar_right'])): ?>
      <div class="sidebar-right">
        <?php print render($page['sidebar_right']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>
