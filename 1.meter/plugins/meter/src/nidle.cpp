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
#include <nidle.hpp>
#include <QPainter>
#include <QFont>

meter_internal_::Nidle::Nidle(QQuickItem* parent)
: QQuickPaintedItem(parent)
, scale_num_(10)
, value_(0.f)
, max_value_(100.f)
, nidle_color_(255, 0, 0, 255)
, danger_zone_(80.f)
, danger_zone_state_(this->value_ > this->danger_zone_ ? true : false)
{
    using NS = meter_internal_::Nidle;
    auto func = [this](){this->update();};
    this->connect(this, &NS::widthChanged, func);
    this->connect(this, &NS::heightChanged, func);
    this->connect(this, &NS::changePropertySignal, func);
}

void meter_internal_::Nidle::paint(QPainter* painter)
{
    if(this->value_ > this->danger_zone_ && !this->danger_zone_state_)
    {
        this->danger_zone_state_ = true;
        emit this->aboveDangerZone();
    }

    if(this->value_ <= this->danger_zone_ && this->danger_zone_state_)
    {
        this->danger_zone_state_ = false;
        emit this->belowDangerZone();
    }

    // ローカル変数
    auto width_unit = this->width() / (this->scale_num_ + 1);
    auto width_unit_half = width_unit * 0.5f;

    // アンチエイリアスとペンの設定
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(this->nidle_color_, 1));

    auto x_nidle = width_unit_half + width_unit * this->scale_num_ * (this->value_ / this->max_value_);
    painter->drawLine( x_nidle, this->height() * 0.1, x_nidle, this->height());
}
