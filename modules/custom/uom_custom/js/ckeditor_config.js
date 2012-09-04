/**
 * Custom configuration for ckeditor.
 *
 * Configuration options can be set here. Any settings described here will be
 * overridden by settings defined in the $settings variable of the hook. To
 * override those settings, do it directly in the hook itself to $settings.
 */
CKEDITOR.editorConfig = function(config) {
  // config.styleSet is an array of objects that define each style available
  // in the font styles tool in the ckeditor toolbar
  config.stylesSet = [
    /* Block Styles */

    // Each style is an object whose properties define how it is displayed
    // in the dropdown, as well as what it outputs as html into the editor
    // text area.
    { name : 'Notice'           , element : 'p'    , attributes : { 'class' : 'notice' } },
    { name : 'Important Notice' , element : 'p'    , attributes : { 'class' : 'importantnotice' } },

    { name : 'Borderless'       , element : 'table', attributes : { 'class' : 'borderless' } },
  ];
}
