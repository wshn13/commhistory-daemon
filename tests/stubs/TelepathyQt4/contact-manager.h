/*
 * This file is part of TelepathyQt4
 *
 * Copyright (C) 2008-2010 Collabora Ltd. <http://www.collabora.co.uk/>
 * Copyright (C) 2008-2010 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TelepathyQt4_contact_manager_h_HEADER_GUARD_
#define _TelepathyQt4_contact_manager_h_HEADER_GUARD_

#include <QObject>

#include <QList>
#include <QSet>

#include "Types"
#include "Contact"
#include "Channel"
#include "ReferencedHandles"
#include "PendingOperation"
#include "PendingContacts"

namespace Tp
{

class ContactManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ContactManager)

public:
    ContactManager();
    ~ContactManager();

    QSet<Contact::Feature> supportedFeatures() const;

    PendingContacts *contactsForHandles(const UIntList &handles,
            const QSet<Contact::Feature> &features = QSet<Contact::Feature>());

    PendingContacts *upgradeContacts(const QList<ContactPtr> &contacts,
            const QSet<Contact::Feature> &features);

Q_SIGNALS:
    void groupMembersChanged(const QString &group,
            const Tp::Contacts &groupMembersAdded,
            const Tp::Contacts &groupMembersRemoved,
            const Tp::Channel::GroupMemberChangeDetails &details);

public: // ut
    void ut_setSupportedFeatures(const QSet<Contact::Feature>& features);
    void ut_emitGroupMembersChanged(const QString &group,
                                    const Tp::Contacts &groupMembersAdded,
                                    const Tp::Contacts &groupMembersRemoved,
                                    const Tp::Channel::GroupMemberChangeDetails &details);

private:
    QSet<Contact::Feature> m_supportedFeatures;
};

} // Tp

#endif