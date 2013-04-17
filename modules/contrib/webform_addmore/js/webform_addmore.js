// $Id$

(function ($) {

Drupal.behaviors.webform_addmore = {
  attach: function(context) {
    function fieldsetRepeater(container, fieldsetSelecter, addBtnTxt, delBtnTxt, numberFirstShown) {
      if ($(fieldsetSelecter).parent().find('input.add-more').length) {
        return;
      }

      var collections = Drupal.settings.webform_addmore.collections;

      if (collections.length == 0) {
        collections.push('');
      }

      for (index in collections) {
        if (collections[index].length == 0) {
          var parent_fieldset_selector = fieldsetSelecter;
        }
        else {
          var parent_fieldset_selector = '#' + collections[index] + ' ' + fieldsetSelecter;
        }
        //console.debug('parent_fieldset_selector: %o', parent_fieldset_selector);
        var add_more_button_id = 'webform-addmore-' + collections[index];
        var del_more_button_id = 'webform-addmore-del-' + collections[index];
        var addBtn = $('<input type="button" id="' + add_more_button_id + '" class="add-more" />').val(addBtnTxt);
        addBtn.click(function() {
          var parent_fieldset = $(this).parents('fieldset');
          if (parent_fieldset.length > 0) {
            var parent_id = parent_fieldset.attr('id');
            var hiddenFieldsets = $('#' + parent_id + ' ' + fieldsetSelecter).not(':visible');
          }
          else {
            var hiddenFieldsets = fieldsets.not(':visible');
          }


          hiddenFieldsets.filter(':first').fadeIn();

          if(hiddenFieldsets.size() < 2) {
            $(this).hide();
          }

          var shownFieldsets = $('#' + parent_id + ' ' + fieldsetSelecter).not(':hidden');
          if(shownFieldsets.size() < 2) {
            $('#' + parent_id).find('.del-btn').hide();
          }
          else {
            $('#' + parent_id).find('.del-btn').show();
          }

        });

        var delBtn = $('<input type="button" id="' + del_more_button_id + '" class="del-btn" />').val(delBtnTxt);
        delBtn.click(function() {
          var parent_fieldset = $(this).parents('fieldset');
          if (parent_fieldset.length > 0) {
            var parent_id = parent_fieldset.attr('id');
            var shownFieldsets = $('#' + parent_id + ' ' + fieldsetSelecter).not(':hidden');
          }
          else {
            var shownFieldsets = fieldsets.not(':hidden');
          }

          shownFieldsets.filter(':last').hide().find(':input').val('');

          // We need to rescan the page for shown fieldsets
          if (parent_fieldset.length > 0) {
            var parent_id = parent_fieldset.attr('id');
            var shownFieldsets = $('#' + parent_id + ' ' + fieldsetSelecter).not(':hidden');
          }
          else {
            var shownFieldsets = fieldsets.not(':hidden');
          }

          if(shownFieldsets.size() < 2) {
            $(this).hide();
          }

          var hiddenFieldsets = $('#' + parent_id + ' ' + fieldsetSelecter).not(':visible');

          if(hiddenFieldsets.size() < 1) {
            $('#' + parent_id).find('.add-more').hide();
          }
          else {
            $('#' + parent_id).find('.add-more').show();
          }
        });

        var fieldsets = container.find(parent_fieldset_selector)
          .not(container.find(parent_fieldset_selector + ' ' + parent_fieldset_selector))
          .hide();

        fieldsets.filter(':last').after($('<div/>').append(delBtn));
        fieldsets.filter(':last').after($('<div/>').append(addBtn));

        var count = 0;
        $.each(fieldsets, function(i, fieldset){
          var val = $(fieldset).find(':input').val();
          if (val.length > 0){
            count += 1;
          }
        })
        if (count > 1) {
          for( var i = 0; i < count; i++ ) {
            addBtn.click();
          }
        }
        else {
          for( var i = 0; i < numberFirstShown; i++ ) {
            addBtn.click();
          }
        }
      }
    }

    Drupal.settings.webform_addmore.collections = new Array();
    $.each(
      Drupal.settings.webform_addmore.fieldsets,
      function(i, fieldset) {
        var parent_fieldset = $('#' + fieldset).parents('fieldset');
        if (parent_fieldset.length > 0) {
          var parent_id = parent_fieldset.attr('id');
          if ($.inArray(parent_id, Drupal.settings.webform_addmore.collections) < 0) {
            Drupal.settings.webform_addmore.collections.push(parent_id);
          }
        }
        $('#' + fieldset).addClass('webform-addmore');
      }
    );

    fieldsetRepeater($('.webform-client-form'), '.webform-addmore', Drupal.settings.webform_addmore.addlabel, Drupal.settings.webform_addmore.dellabel, 1);
  }
};

})(jQuery);
