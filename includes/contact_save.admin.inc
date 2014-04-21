<?php
/**
 * @file
 * Contact save module admin logic.
 */

/**
 * Contact save settings form.
 */
function contact_save_settings($form, &$form_state) {
  $form = array();

  $options = array(
    0 => t('Never'),
  );
  $options += drupal_map_assoc(
    array(
      86400,
      259200,
      604800,
      1209600,
      2419200,
      9676800,
    ),
    'format_interval'
  );

  $form['contact_save_live_time'] = array(
    '#type' => 'select',
    '#title' => t('Delete messages older than'),
    '#required' => TRUE,
    '#options' => $options,
    '#default_value' => variable_get('contact_save_live_time', 0),
    '#description' => t('Old messages will be automatically deleted. (Requires a correctly configured <a href="@cron">cron maintenance task</a>.)', array('@cron' => url('admin/reports/status'))),
  );

  return system_settings_form($form);
}

/**
 * Message delete form.
 */
function contact_save_message_delete_form($form, &$form_state, $id) {
  $form = array();

  $form['contact_save_message_delete']['id'] = array(
    '#type' => 'hidden',
    '#value' => $id,
  );

  $confirm_question = t('Are you sure you want to delete this item?');

  return confirm_form($form, $confirm_question, CONTACT_SAVE_MESSAGES_LIST_PATH, t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Submit form for delete confirm page.
 */
function contact_save_message_delete_form_submit($form, &$form_state) {
  contact_save_message_delete($form_state['values']['id']);
  $form_state['redirect'] = CONTACT_SAVE_MESSAGES_LIST_PATH;
}
