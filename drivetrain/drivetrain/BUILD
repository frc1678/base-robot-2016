cc_library(
  name = 'polydrivetrain_plants',
  srcs = [
    'polydrivetrain_dog_motor_plant.cc',
    'drivetrain_dog_motor_plant.cc',
  ],
  hdrs = [
    'polydrivetrain_dog_motor_plant.h',
    'drivetrain_dog_motor_plant.h',
  ],
  deps = [
    '//drivetrain:state_feedback_loop',
  ],
)

#TODO (Finn): Maybe move things into the outer drivetrain folder? Will require redoing all the includes.
cc_library(
  name = 'drivetrain_lib',
  srcs = [
    'drivetrain.cc',
    'polydrivetrain_cim_plant.cc',
    'drivetrain_dog_motor_plant.cc',
    'polydrivetrain_dog_motor_plant.cc',
  ],
  hdrs = [
    'drivetrain.h',
    'polydrivetrain_cim_plant.h',
    'drivetrain_dog_motor_plant.h',
    'polydrivetrain_dog_motor_plant.h',
    'commonmath.h',
  ],
  deps = [
    '//drivetrain:polytope',
    '//drivetrain:state_feedback_loop',
    '//drivetrain:coerce_goal',
  ],
  visibility = ["//visibility:public"],
)

cc_test(
  name='drivetrain_lib_test',
  srcs = [
    'drivetrain_lib_test.cc'
  ],
  deps = [
    '//drivetrain:state_feedback_loop',
    '//drivetrain:coerce_goal',  
    'drivetrain_lib',
    '@gtest//:main',
  ],
  visibility = ["//visibility:public"],
)
