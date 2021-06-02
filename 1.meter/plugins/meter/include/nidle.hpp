/*-------------------------------------------------------------------------------
                           Copyright (c) 2021 DIODE.
    
    This file is part of meter.
    
    meter is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    meter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with meter.  If not, see <https://www.gnu.org/licenses/>.
*///-----------------------------------------------------------------------------
#pragma once

#include <QQuickPaintedItem>

namespace meter_internal_
{
    class Nidle;
}

class meter_internal_::Nidle
: public QQuickPaintedItem
{
    Q_OBJECT

    unsigned scale_num_;
    float value_;
    float max_value_;
    QColor nidle_color_;
    float danger_zone_;
    bool danger_zone_state_;

    Q_PROPERTY(unsigned scale_num MEMBER scale_num_ NOTIFY changePropertySignal)
    Q_PROPERTY(float danger_zone MEMBER danger_zone_ NOTIFY changePropertySignal)
    Q_PROPERTY(float value MEMBER value_ NOTIFY changePropertySignal)
    Q_PROPERTY(float max_value MEMBER max_value_ NOTIFY changePropertySignal)
    Q_PROPERTY(QColor nidle_color MEMBER nidle_color_ NOTIFY changePropertySignal)

public:
    explicit Nidle(QQuickItem* parent = nullptr);
    void paint(QPainter* painter)override;

signals:
    void changePropertySignal();
    void aboveDangerZone(); //レッドゾーンを超えた場合に発信されるシグナル
    void belowDangerZone(); //レッドゾーンを下回った時に発信されるシグナル
};
