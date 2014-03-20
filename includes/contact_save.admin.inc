<?php

/**
 * Contact save settings form.
 */
function contact_save_settings($form, &$form_state) {
  $form = array();

  $form['test'] = array(
    '#markup' => 'Settings will be here',
  );

  return $form;
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

  return confirm_form($form, $confirm_question, 'admin/reports/contact/messages', t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Submit form for delete confirm page.
 */
function contact_save_message_delete_form_submit($form, &$form_state) {
  // TODO: Add function to delete a message.
  $form_state['redirect'] = 'admin/reports/contact/messages';
}
