#ifndef CARD_H
#define CARD_H

#include <QMainWindow>

class Card : public QMainWindow
{
    public:
    Card( QWidget* parent = nullptr );
    ~Card() = default;
};

#endif

