<?php

/**
 * @file
 * Provide views data and handlers for contact_save.module.
 */

/**
 * Implements hook_views_data().
 */
function contact_save_views_data() {
  $data['contact_save']['table']['group'] = t('Contact submissions');

  $data['contact_save']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Submissions'),
    'help' => t('Contact submissions'),
  );

  $data['contact_save']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['contact_save']['table']['join'] = array(
    'contact' => array(
      'left_field' => 'cid',
      'field' => 'cid',
    ),
  );

  $data['contact_save']['id'] = array(
    'title' => t('Message ID'),
    'help' => t('Contact message ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'name field' => 'cid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['contact_save']['cid'] = array(
    'title' => t('Contact ID'),
    'help' => t('Contact ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'name field' => 'cid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['contact_save']['uid'] = array(
    'title' => t('Uid'),
    'help' => t('Submissions user ID'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name',
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['contact_save']['mail'] = array(
    'title' => t('E-mail'),
    'help' => t('Email address for a given user. This field is normally not shown to users, so be cautious when using it.'),
    'field' => array(
      'handler' => 'views_handler_field_user_mail',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['contact_save']['subject'] = array(
    'title' => t('Message subject'),
    'help' => t("Submission message subject."),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => filter_fallback_format(),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['contact_save']['message'] = array(
    'title' => t('Message'),
    'help' => t("Submission message."),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => filter_fallback_format(),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );

  $data['contact_save']['created'] = array(
    'title' => t('Submissions created'),
    'help' => t('Time when submissions was done.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['contact_save']['delete_message'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the message.'),
      'handler' => 'contact_save_handler_message_link_delete',
    ),
  );

  return $data;
}
