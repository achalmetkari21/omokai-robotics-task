#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "mission_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__mission_interfaces__msg__Mission() -> *const std::ffi::c_void;
}

#[link(name = "mission_interfaces__rosidl_generator_c")]
extern "C" {
    fn mission_interfaces__msg__Mission__init(msg: *mut Mission) -> bool;
    fn mission_interfaces__msg__Mission__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Mission>, size: usize) -> bool;
    fn mission_interfaces__msg__Mission__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Mission>);
    fn mission_interfaces__msg__Mission__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Mission>, out_seq: *mut rosidl_runtime_rs::Sequence<Mission>) -> bool;
}

// Corresponds to mission_interfaces__msg__Mission
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Mission {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: f32,

}



impl Default for Mission {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !mission_interfaces__msg__Mission__init(&mut msg as *mut _) {
        panic!("Call to mission_interfaces__msg__Mission__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Mission {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mission_interfaces__msg__Mission__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mission_interfaces__msg__Mission__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mission_interfaces__msg__Mission__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Mission {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Mission where Self: Sized {
  const TYPE_NAME: &'static str = "mission_interfaces/msg/Mission";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__mission_interfaces__msg__Mission() }
  }
}


