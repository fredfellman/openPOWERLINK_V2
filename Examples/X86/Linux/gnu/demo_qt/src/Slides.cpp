/****************************************************************************

  (c) SYSTEC electronic GmbH, D-07973 Greiz, August-Bebel-Str. 29
      www.systec-electronic.com

  Project:      openPOWERLINK

  Description:  source file for Qt Slides widget,
                which represents the digital outputs

  License:

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. Neither the name of SYSTEC electronic GmbH nor the names of its
       contributors may be used to endorse or promote products derived
       from this software without prior written permission. For written
       permission, please contact info@systec-electronic.com.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    Severability Clause:

        If a provision of this License is or becomes illegal, invalid or
        unenforceable in any jurisdiction, that shall not affect:
        1. the validity or enforceability in that jurisdiction of any other
           provision of this License; or
        2. the validity or enforceability in other jurisdictions of that or
           any other provision of this License.

  -------------------------------------------------------------------------

                $RCSfile$

                $Author$

                $Revision$  $Date$

                $State$

                Build Environment:
                    GCC V3.4

  -------------------------------------------------------------------------

  Revision History:

  2008/04/11 m.u.:   start of the implementation

****************************************************************************/

#include <QLCDNumber>
#include <QVBoxLayout>
#include <QPalette>
#include <QLabel>

#include "Slides.h"
#include "Leds.h"
#include "Circles.h"


Slides::Slides(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *pSlideLayout = new QVBoxLayout;
    setLayout(pSlideLayout);

    QFont LabelFont;
    LabelFont.setBold(true);
    LabelFont.setPointSize(18);

    QLabel* pDigiOutLabel = new QLabel("Digital Outputs:");
    pDigiOutLabel->setFont(LabelFont);
    pSlideLayout->addWidget(pDigiOutLabel);

    QPalette PalLeds;
    PalLeds.setColor(QPalette::Active, QPalette::Window, Qt::red);
    PalLeds.setColor(QPalette::Active, QPalette::Button, Qt::red);
    PalLeds.setColor(QPalette::Inactive, QPalette::Window, Qt::red);
    PalLeds.setColor(QPalette::Inactive, QPalette::Button, Qt::red);

    m_pDigiOutLeds = new Leds(10, 30, PalLeds);
    pSlideLayout->addWidget(m_pDigiOutLeds);


    m_pCircles = new Circles(10, QPen(Qt::red, 10));
    pSlideLayout->addWidget(m_pCircles, 4);

/*
    pLcd1 = new QLCDNumber(2);
    pLcd1->display(0);
    pLcd1->setSegmentStyle(QLCDNumber::Filled);
    pLcd1->setMaximumHeight(400);
    pLcd1->setFrameShape(QFrame::NoFrame);
    pLcd1->setMode(QLCDNumber::Hex);
    //pLcd2 = new QLCDNumber(1);
    //pLcd2->display(0);
    //pLcd2->setSegmentStyle(QLCDNumber::Filled);
    //pLcd2->setFrameShape(QFrame::NoFrame);
    //pLcd2->setMode(QLCDNumber::Hex);
    pSlideLayout->addStretch(1);
    pSlideLayout->addWidget(pLcd1, 4);
    //pSlideLayout->addWidget(pLcd2, 4);
*/

    pSlideLayout->addStretch(1);

}

void Slides::setValue(unsigned int uiDataIn_p)
{
//    pLcd1->display((int)(uiDataIn_p & 0xFF));
    m_pCircles->setValue(uiDataIn_p);
    m_pDigiOutLeds->setLeds(uiDataIn_p);
    //pLcd2->display((int)(uiDataIn_p & 0x0F));
}
