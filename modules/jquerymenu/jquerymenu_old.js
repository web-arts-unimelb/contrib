(function ($) {
  Drupal.behaviors.jquerymenu = function(context) {
    $('ul.jquerymenu .active').parents('li').removeClass('closed').addClass('open');
    $('ul.jquerymenu .active').parents('li').children('span.parent').removeClass('closed').addClass('open');
    
    jqm_showit = function() {
      $(this).children('.jqm_link_edit').fadeIn();
    }
    jqm_hideit = function() {
      $(this).children('.jqm_link_edit').fadeOut();
    }
    $('ul.jquerymenu li').hover(jqm_showit, jqm_hideit);
      $('ul.jquerymenu:not(.jquerymenu-processed)', context).addClass('jquerymenu-processed').each(function(){
      $(this).find("li.parent span.parent").click(function(){
        momma = $(this).parent();
        if ($(momma).hasClass('closed')){
          $($(this).siblings('ul').children()).hide().fadeIn('3000');
          $(momma).children('ul').slideDown('700');
          $(momma).removeClass('closed').addClass('open');
          $(this).removeClass('closed').addClass('open');
        }
        else{
          $(momma).children('ul').slideUp('700');
          $($(this).siblings('ul').children()).fadeOut('3000');
          $(momma).removeClass('open').addClass('closed');
          $(this).removeClass('open').addClass('closed');
        }
      });
    });
  };
})(jQuery);