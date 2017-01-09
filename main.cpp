#include <QApplication>

#include "card.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    auto card = new Card();
    card->show();

    return app.exec();
}

