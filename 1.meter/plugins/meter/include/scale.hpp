#pragma once

#include <QQuickPaintedItem>

namespace meter_internal_
{
    class Scale;
}

class meter_internal_::Scale
: public QQuickPaintedItem
{
    Q_OBJECT

    unsigned scale_num_;
    float max_value_;
    float danger_zone_;
    QColor danger_zone_color_;
    bool danger_zone_visible_;
    unsigned decimal_place_;
    QColor scale_color_;

    Q_PROPERTY(unsigned scale_num MEMBER scale_num_ NOTIFY changePropertySignal)
    Q_PROPERTY(float max_value MEMBER max_value_ NOTIFY changePropertySignal)
    Q_PROPERTY(float danger_zone MEMBER danger_zone_ NOTIFY changePropertySignal)
    Q_PROPERTY(QColor danger_zone_color MEMBER danger_zone_color_ NOTIFY changePropertySignal)
    Q_PROPERTY(bool danger_zone_visible MEMBER danger_zone_visible_ NOTIFY changePropertySignal)
    Q_PROPERTY(unsigned decimal_place MEMBER decimal_place_ NOTIFY changePropertySignal)
    Q_PROPERTY(QColor scale_color MEMBER scale_color_ NOTIFY changePropertySignal)

public:
    explicit Scale(QQuickItem* parent = nullptr);
    void paint(QPainter* painter)override;

signals:
    void changePropertySignal();
};
