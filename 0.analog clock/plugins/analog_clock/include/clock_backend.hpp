/*-------------------------------------------------------------------------------
                           Copyright (c) 2021 DIODE.
    
    This file is part of analog clock.
    
    analog clock is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    analog clock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with analog clock.  If not, see <https://www.gnu.org/licenses/>.
*///-----------------------------------------------------------------------------
#pragma once

#include <QObject>
#include <QTime>

namespace clock_component
{
    class ClockBackend;
}

class clock_component::ClockBackend
: public QObject
{
	Q_OBJECT

public:
    Q_INVOKABLE int get_hour() const;
    Q_INVOKABLE int get_minute() const;
    Q_INVOKABLE int get_second() const;
};
