<?php

/**
 * Displays contact form submissions.
 */
function contact_save_submissions($form, &$form_state) {
  $form = array();

  $submissions = contact_save_get_submissions();

  foreach ($submissions as $mail) {
		//
  }

  $form['test'] = array(
    '#markup' => 'Hello',
  );

  return $form;
}
