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

#ifndef QXSPINBOX_QEXPRESSIONDOUBLESPINBOX_H
#define QXSPINBOX_QEXPRESSIONDOUBLESPINBOX_H

#include <QXSpinBox/qxspinboxglobal.h>

#include <QDoubleSpinBox>

namespace QXSpinBox {
    class QXSPINBOX_EXPORT QExpressionDoubleSpinBox : public QDoubleSpinBox {
        Q_OBJECT
    public:
        explicit QExpressionDoubleSpinBox(QWidget *parent = nullptr);
        ~QExpressionDoubleSpinBox();

        QString cleanText() const = delete;

        QString prefix() const = delete;
        void setPrefix(const QString &) = delete;
        QString suffix() const = delete;
        void setSuffix(const QString &) = delete;

        QValidator::State validate(QString &input, int &pos) const override;
        void fixup(QString &str) const override;
    };
}

#endif //QXSPINBOX_QEXPRESSIONDOUBLESPINBOX_H
