/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */
#include "SonarStep.h"
#include "SonarState.h"

void SonarStep::complete() {
  isLogged = true;
  state->success(name);
}

void SonarStep::fail(std::string message) {
  isLogged = true;
  state->failed(name, message);
}

SonarStep::SonarStep(std::string step, SonarState* s) {
  state = s;
  name = step;
}

SonarStep::~SonarStep() {
  if (!isLogged) {
    state->failed(name, "");
  }
}
