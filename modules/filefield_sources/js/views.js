(function ($) {
  Drupal.behaviors.fielfield_sources_views = {
    attach: function(context, settings) {
      $('.fielfield-source-button', context).click(
        function () {
          var fid  = $('span', this).attr('data-fid');
          var cont = $(this).parentsUntil(".filefield-source.filefield-source-views").parent();
          var text = $('.field-container input[type=text]', cont[0]);
          text.attr('value', '[fid:' + fid + ']');
          $('.field-container input[type=submit]', cont[0]).mousedown();
        }
      )
    }
  }
})(jQuery);
