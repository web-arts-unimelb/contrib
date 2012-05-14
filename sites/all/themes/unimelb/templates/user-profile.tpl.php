<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 */
?>
<div class="profile"<?php print $attributes; ?>>
	<?php
		$uid = null;
		$link_array = null;
		$profile_type_array = array();

		if( isset($user_profile["field_first_name"]["#object"]) )
		{
			$user_profile_obj = $user_profile["field_first_name"]["#object"];
			$uid = $user_profile_obj->uid;

			if( isset($user_profile_obj->field_profile_type["und"]) )
			{
				foreach($user_profile_obj->field_profile_type["und"] as $profile_type_obj)
				{
					$profile_type_array[] = $profile_type_obj["value"];		
				}
	
				$link_array = __build_profile_links($profile_type_array, $uid);				
			}
		}
		else
		{
			// Go somewhere
		}
	?>
	
	<br/>
	<p>
		<?php 
			$num = count($link_array);
			if($num > 0)
			{
				echo "<ul>";
				foreach($link_array as $link)
				{
					$profile_type = strtolower($link['profile_type']); 
					$url = $link["url"];
					echo "<li>To view your $profile_type profile, please visit <a href='$url'>this page</a>.</li>";
				}
				echo "</ul>";
			}
			else
			{

			}
		?>
	</p>
</div>


<?php
	// Build your functions here
	function __build_profile_links($profile_type_array = array(), $uid)
	{
		global $base_url;		
		$link_array = null;	
		$index = 0;

		foreach($profile_type_array as $profile_type)
		{
			if($profile_type == "Academic Staff")
			{
				$link_array[$index]["url"] = $base_url. "/about-us/academic-staff/$uid";
				$link_array[$index]["profile_type"] = $profile_type;
			}
			elseif($profile_type == "Professional Staff")
			{
				$link_array[$index]["url"] = $base_url. "/about-us/professional-staff/$uid";
				$link_array[$index]["profile_type"] = $profile_type;
			}
		
			++$index;
		}

		return $link_array;
	}

?>
