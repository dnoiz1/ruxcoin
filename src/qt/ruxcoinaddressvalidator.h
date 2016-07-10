// Copyright (c) 2011-2014 The Ruxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RUXCOIN_QT_RUXCOINADDRESSVALIDATOR_H
#define RUXCOIN_QT_RUXCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class RuxcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit RuxcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Ruxcoin address widget validator, checks for a valid ruxcoin address.
 */
class RuxcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit RuxcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // RUXCOIN_QT_RUXCOINADDRESSVALIDATOR_H
