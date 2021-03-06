// Copyright 1996-2021 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Description:  Class defining the accelerometer group box
 */

#ifndef MAGNETOMETER_GROUP_BOX_HPP
#define MAGNETOMETER_GROUP_BOX_HPP

#include <QtWidgets/QGroupBox>

class QVBoxLayout;
class QLabel;
class QColor;
class MagnetometerGroupBox : public QGroupBox {
public:
  explicit MagnetometerGroupBox(QWidget *parent = 0);
  virtual ~MagnetometerGroupBox();
  void updateValues();

protected:
  QVBoxLayout *mVBox;
  QLabel *mLabels[3];
};

#endif  // MAGNETOMETER_GROUP_BOX_HPP
