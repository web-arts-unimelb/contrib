<div class="featured">

<div class="pullout">

  <ul class="col-3 first">

<?php 

foreach ($items as $delta => $item) { 

	print '<li><a href="' . render($item) . '">';

	print render($item);

	print '</a></li>';

}

?>

  </ul>

<div class="clearfix"></div>

</div>

</div>
