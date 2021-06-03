import QtQuick 2.15

ShaderEffect {
    id: shaderEffect

    width: parent.width
    height: parent.height
    x: parent.x
    y: parent.y

    property int time_2p: 8000
    property real time: 0
    property real freq: 0.005
    property real gain: 1.
    property real thickness: 1.
    property color color1: "#00008b"
    property color color2: "#4b0082"

    NumberAnimation on time {
        id: time_anim
        from: 0
        to: Math.PI * 2
        duration: time_2p
        loops: Animation.Infinite
    }

    fragmentShader: "
    varying highp vec2 qt_TexCoord0;
    uniform lowp float qt_Opacity;

    uniform highp float gain;
    uniform highp float time;
    uniform highp float freq;
    uniform highp float thickness;
    uniform highp vec4 color1;
    uniform highp vec4 color2;

    void main( void )
    {
        const double PI = 3.141592653589793238462643f;
        const double PI2 = 2f * PI;
        float freq_t = 30f * freq;
        float sin_arg = PI2 * qt_TexCoord0.x * freq_t + time;
        float col = qt_TexCoord0.y - thickness * (sin(sin_arg) * gain * 0.5f + 0.5f);
        gl_FragColor = mix(color2, color1, clamp(col, 0.f, 1.f)) * qt_Opacity;
    }
    "
}
