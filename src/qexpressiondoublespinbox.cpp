/**********************************************************************************
 * Copyright (c) 2024 Crindzebra Sjimo                                            *
 *                                                                                *
 * This file is part of QXSpinBox.                                                *
 *                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          *
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in all *
 * copies or substantial portions of the Software.                                *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 * SOFTWARE.                                                                      *
 **********************************************************************************/

#include "QXSpinBox/qexpressiondoublespinbox.h"

#include "tinyexpr.h"

namespace QXSpinBox {

    QExpressionDoubleSpinBox::QExpressionDoubleSpinBox(QWidget *parent) : QDoubleSpinBox(parent) {
    }

    QExpressionDoubleSpinBox::~QExpressionDoubleSpinBox() = default;

    QValidator::State QExpressionDoubleSpinBox::validate(QString &input, int &pos) const {
        if (textFromValue(valueFromText(input)) == input)
            return QValidator::Acceptable;
        else
            return QValidator::Intermediate;
    }

    void QExpressionDoubleSpinBox::fixup(QString &str) const {
        int err;
        auto s = str;
        for (auto &c : s) {
            if (c.unicode() >= 0xff01 && c.unicode() <= 0xff5e) {
                c.unicode() -= 0xfee0;
            }
        }
        double ret = te_interp(s.toLatin1(), &err);
        if (err == 0) {
            str = textFromValue(ret);
        }
    }

}