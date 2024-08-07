///////////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2024 Edouard Griffiths, F4EXB <f4exb06@gmail.com>                   //
//                                                                                   //
// This program is free software; you can redistribute it and/or modify              //
// it under the terms of the GNU General Public License as published by              //
// the Free Software Foundation as version 3 of the License, or                      //
// (at your option) any later version.                                               //
//                                                                                   //
// This program is distributed in the hope that it will be useful,                   //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                    //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                      //
// GNU General Public License V3 for more details.                                   //
//                                                                                   //
// You should have received a copy of the GNU General Public License                 //
// along with this program. If not, see <http://www.gnu.org/licenses/>.              //
///////////////////////////////////////////////////////////////////////////////////////
#ifndef INCLUDE_WDSPRXPANDIALOG_H
#define INCLUDE_WDSPRXPANDIALOG_H

#include <QDialog>

#include "wdsprxsettings.h"

namespace Ui {
    class WDSPRxPanDialog;
}

class WDSPRxPanDialog : public QDialog {
    Q_OBJECT
public:
    enum ValueChanged {
        ChangedPan,
    };

    explicit WDSPRxPanDialog(QWidget* parent = nullptr);
    ~WDSPRxPanDialog() override;

    void setPan(double pan);
    double getPan() const { return m_pan; }

signals:
    void valueChanged(int valueChanged);

private:
    Ui::WDSPRxPanDialog *ui;
    double m_pan;

private slots:
    void on_zero_clicked();
    void on_pan_valueChanged(int value);
};

#endif
