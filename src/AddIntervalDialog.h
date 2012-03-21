/*
 * Copyright (c) 2012 Damien Grauser (Damien.Grauser@pev-geneve.ch)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_AddIntervalDialog_h
#define _GC_AddIntervalDialog_h 1
#include "GoldenCheetah.h"

#include <QtGui>

class MainWindow;
class RideFile;

class AddIntervalDialog : public QDialog
{
    Q_OBJECT
    G_OBJECT


    public:

        struct AddedInterval {
            QString name;
            double start, stop, avg;
            AddedInterval(double start, double stop, double avg) :
                start(start), stop(stop), avg(avg) {}
        };

        AddIntervalDialog(MainWindow *mainWindow);

        static void findPeakPowerStandard(const RideFile *ride, QList<AddedInterval> &results);

        static void findBests(bool typeTime, const RideFile *ride, double windowSizeSecs,
                              int maxIntervals, QList<AddedInterval> &results, QString name);

        static void findFirsts(bool typeTime, const RideFile *ride, double windowSizeSecs,
                               int maxIntervals, QList<AddedInterval> &results);

    private slots:
        void createClicked();
        void doneClicked();
        void addClicked(); // add to inverval selections

        void methodFirstClicked();
        void methodBestPowerClicked();
        void peakPowerStandardClicked();
        void peakPowerCustomClicked();
        void typeTimeClicked();
        void typeDistanceClicked();

    private:

        MainWindow *mainWindow;
        QWidget *intervalMethodWidget, *intervalPeakPowerWidget, *intervalTypeWidget, *intervalTimeWidget, *intervalDistanceWidget, *intervalCountWidget;

        QHBoxLayout *intervalPeakPowerTypeLayout;
        QPushButton *createButton, *doneButton, *addButton;
        QDoubleSpinBox *hrsSpinBox, *minsSpinBox, *secsSpinBox, *countSpinBox,*kmsSpinBox, *msSpinBox;
        QRadioButton *methodFirst, *methodBestPower, *typeDistance, *typeTime, *peakPowerStandard, *peakPowerCustom;
        QTableWidget *resultsTable;
};

#endif // _GC_AddIntervalDialog_h

