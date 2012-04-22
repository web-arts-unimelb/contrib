<div class="featured">

<div class="pullout">

  <ul class="col-3 first">

<?php 

foreach ($items as $delta => $item) { 

	print '<li>';

	print render($item);

	print '</li>';

}

?>

  </ul>

<div class="clearfix"></div>

</div>

</div>