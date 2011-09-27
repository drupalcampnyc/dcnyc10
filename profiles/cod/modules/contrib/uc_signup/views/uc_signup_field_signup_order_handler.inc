<?php 
class uc_signup_field_signup_order_handler extends views_handler_field {
  function render($values) {
    return l($values->uc_signup_log_oid, 'admin/store/orders/'. $values->uc_signup_log_oid);
  }
}