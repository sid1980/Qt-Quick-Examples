#include <scale.hpp>
#include <QPainter>
#include <QFont>

meter_internal_::Scale::Scale(QQuickItem* parent)
: QQuickPaintedItem(parent)
, scale_num_(10)
, max_value_(100.f)
, danger_zone_(80.f)
, danger_zone_color_(255, 0, 0, 180)
, danger_zone_visible_(true)
, decimal_place_(1)
, scale_color_(0, 0, 0, 255)
{
    using NS = meter_internal_::Scale;
    auto func = [this](){this->update();};
    this->connect(this, &NS::widthChanged, func);
    this->connect(this, &NS::heightChanged, func);
    this->connect(this, &NS::changePropertySignal, func);
}

void meter_internal_::Scale::paint(QPainter* painter)
{
    // ローカル変数
    auto width_unit = this->width() / (this->scale_num_ + 1);
    auto width_unit_half = width_unit * 0.5f;
    auto font = QFont();
    auto text = QString();
    auto draw_x = float();

    // アンチエイリアスとペンの設定
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 1));
    font.setPixelSize(width_unit / QString::number(this->max_value_, 'f', 1).length());
    painter->setFont(font);
    auto fm = QFontMetrics(font);

    if(this->danger_zone_visible_)
    {
        // レッドゾーン描画
        auto x_end = this->width() - width_unit_half;
        auto x_start = width_unit_half + width_unit * this->scale_num_ * (this->danger_zone_ / this->max_value_);
        painter->fillRect(
            x_start,
            0,
            x_end - x_start,
            this->height() * 0.2,
            this->danger_zone_color_
        );
    }

    // 目盛り描画
    painter->drawLine(width_unit_half, 0, this->width() - width_unit_half, 0);

    for(auto i=0ULL; i<this->scale_num_ + 1; ++i)
    {
        draw_x = width_unit * i + width_unit_half;

        painter->drawLine(draw_x, 0, draw_x, this->height() * 0.4f);

        text = QString::number((this->max_value_ / this->scale_num_) * i, 'f', this->decimal_place_);

        painter->drawText(
            draw_x - fm.horizontalAdvance(text) * 0.5f,
            this->height() * 0.4 + fm.height(),
            text
        );
    }

    for(auto i=0ULL; i<this->scale_num_; ++i)
        painter->drawLine(
            width_unit * i + 2.f * width_unit_half,
            0,
            width_unit * i + 2.f * width_unit_half,
            this->height() * 0.3f
        );
}
