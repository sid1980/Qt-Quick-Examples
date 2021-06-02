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
