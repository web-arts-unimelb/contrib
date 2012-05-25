<div class="featured">
	<div class="pullout">
  		<ul class="col-3 first">
			<?php
				if(isset($element["#object"]->field_related_url))
				{
					$url_obj = $element["#object"]->field_related_url;

					if(count($url_obj["und"]) > 0)
					{
						foreach($url_obj["und"] as $entity)
						{
							$url = $entity["display_url"];
							$title = $entity["title"];
							echo "<li><a href=\"$url\">$title</a></li>";
						}
					}
				}				
			?>
  		</ul>
		<div class="clearfix"></div>
	</div>
</div>
