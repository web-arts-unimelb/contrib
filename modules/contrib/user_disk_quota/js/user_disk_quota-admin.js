(function($) {
  Drupal.behaviors.user_disk_quota_admin = {
    attach: function (context, settings) {
      $( ".user-disk-percentage-slider-range-max" ).slider({
        range: "max",
        min: 1,
        max: 100,
        value: settings.user_disk_quota_admin.default_percentage,
        slide: function( event, ui ) {
          $( ".user-disk-percentage-slider" ).val( ui.value );
        }
      });
      $( ".user-disk-percentage-slider" ).change(function(){
        //TODO check if numeric and in 0/100 range
        $( ".user-disk-percentage-slider-range-max" ).slider( "option", "value", $(this).val() );
      });
    }
  };
})(jQuery);