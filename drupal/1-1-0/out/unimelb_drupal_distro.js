(function ($) {
	Drupal.behaviors.D7UNIMELB = {
		attach: function(context, settings) {




$('#g-local-global-search').css('display','none');

$('#g-search-button').live('click', function(){

	$('#g-local-global-search').css('display','block');

});

$("body").click(function() {

	$('#g-local-global-search').css('display','none');

});



$("#g-local-global-search input").click(function(e) {
    e.stopPropagation();
});


		}
	};
})(jQuery);
