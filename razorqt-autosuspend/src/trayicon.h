/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Razor - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2011 Razor team
 * Authors:
 *   Christian Surlykke <christian@surlykke.dk>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QWidget>
#include <QIcon>
#include <QVariantMap>
#include <QMap>
#include <razorqt/razorsettings.h>
#include "batteryinfo.h"
#include "battery.h"

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    TrayIcon(Battery* battery, QObject *parent = 0);
    ~TrayIcon();

private:
    void updateStatusIcon(); 
    void updateToolTip();
    void updateStateAsString();

    void  checkThemeStatusIcons();
    bool mThemeHasStatusIcons;
   
    void setUpstatusIcons();
    QIcon mStatusIconsCharging[11];
    QIcon mStatusIconsDecharging[11];
    
    Battery* mBattery; 
    BatteryInfo mBatteryInfo;
    RazorSettings mSettings;

private slots:
    void update();
    void iconThemeChanged();
    void settingsChanged();
    void showStatus(QSystemTrayIcon::ActivationReason reason);

};

#endif // MAINWINDOW_H
