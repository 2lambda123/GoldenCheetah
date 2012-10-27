/*
 * Copyright (c) 2012 Mark Liversedge (liversedge@gmail.com)
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

#ifndef _GC_Lucene_h
#define _GC_Lucene_h

#include <QObject>
#include <QString>
#include <QDir>

#include "MainWindow.h"
#include "RideMetadata.h"
#include "SummaryMetrics.h"
#include "RideFile.h"

#include "CLucene.h"
#include "CLucene/index/IndexModifier.h"

using namespace lucene::analysis;
using namespace lucene::index;
using namespace lucene::document;
using namespace lucene::queryParser;
using namespace lucene::search;
using namespace lucene::store;

class Lucene : public QObject
{
    Q_OBJECT

public:
    Lucene(MainWindow *parent = 0);
    ~Lucene();

    // Create/Delete Metrics
	bool importRide(SummaryMetrics *summaryMetrics, RideFile *ride, QColor color, unsigned long, bool);
    bool deleteRide(QString);
    void optimise(); // for optimising the index once updated

    // search
    int search(QString query); // run query and return number of results found
    QStringList &files() { return filenames; }

protected:

private slots:

signals:

private:
    MainWindow *main;
    QDir dir;

    // CLucene objects
    lucene::analysis::standard::StandardAnalyzer analyzer;

    // Query results
    Hits *hits; // null when no results
    QStringList filenames;
};

#endif
