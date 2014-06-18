/***********************************************************************
*
* Copyright (c) 2012-2014 Barbara Geller
* Copyright (c) 2012-2014 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

/*!
    \class QQueue
    \brief The QQueue class is a generic container that provides a queue.

    \ingroup tools
    \ingroup shared

    \reentrant

    QQueue\<T\> is one of Qt's generic \l{container classes}. It
    implements a queue data structure for items of a same type.

    A queue is a first in, first out (FIFO) structure. Items are
    added to the tail of the queue using enqueue() and retrieved from
    the head using dequeue(). The head() function provides access to
    the head item without removing it.

    Example:
    \snippet doc/src/snippets/code/src_corelib_tools_qqueue.cpp 0

    The example will output 1, 2, 3 in that order.

    QQueue inherits from QList. All of QList's functionality also
    applies to QQueue. For example, you can use isEmpty() to test
    whether the queue is empty, and you can traverse a QQueue using
    QList's iterator classes (for example, QListIterator). But in
    addition, QQueue provides three convenience functions that make
    it easy to implement FIFO semantics: enqueue(), dequeue(), and
    head().

    QQueue's value type must be an \l{assignable data type}. This
    covers most data types that are commonly used, but the compiler
    won't let you, for example, store a QWidget as a value. Use
    QWidget* instead.

    \sa QList, QStack
*/

/*!
    \fn QQueue::QQueue()

    Constructs an empty queue.
*/

/*!
    \fn QQueue::~QQueue()

    Destroys the queue. References to the values in the queue, and all
    iterators over this queue, become invalid.
*/

/*!
    \fn void QQueue::swap(QQueue<T> &other)
    \since 4.8

    Swaps queue \a other with this queue. This operation is very
    fast and never fails.
*/

/*!
    \fn void QQueue::enqueue(const T& t)

    Adds value \a t to the tail of the queue.

    This is the same as QList::append().

    \sa dequeue(), head()
*/

/*!
    \fn T &QQueue::head()

    Returns a reference to the queue's head item. This function
    assumes that the queue isn't empty.

    This is the same as QList::first().

    \sa dequeue(), enqueue(), isEmpty()
*/

/*!
    \fn const T &QQueue::head() const

    \overload
*/

/*!
    \fn T QQueue::dequeue()

    Removes the head item in the queue and returns it. This function
    assumes that the queue isn't empty.

    This is the same as QList::takeFirst().

    \sa head(), enqueue(), isEmpty()
*/
