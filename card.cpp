#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>

#include "card.h"

Card::Card( QWidget* parent ) : QMainWindow( parent )
{
    // Create the layout first
    auto grid = new QGridLayout();

    // Global disabler of all other options
    auto indentWhatThe = new QHBoxLayout;
    auto indentWhatTheSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentWhatThe->addSpacerItem( indentWhatTheSpacer );
    auto optionWhatThe = new QRadioButton( "What The" );
    indentWhatThe->addWidget( optionWhatThe );

    grid->addLayout( indentWhatThe, 0, 0, 1, -1 );

    // Main text
    auto text = new QLabel( "F U C K" );
    grid->addWidget( text, 1, 0, 1, -1, Qt::AlignCenter );

    // Rest of the buttons
    auto optionMe = new QRadioButton( "Me" );
    grid->addWidget( optionMe, 2, 0 );

    auto optionThat = new QRadioButton( "That" );
    grid->addWidget( optionThat, 2, 2 );

    auto optionThis = new QRadioButton( "This" );
    grid->addWidget( optionThis, 2, 4 );

    auto optionYes = new QRadioButton( "Yes" );
    grid->addWidget( optionYes, 3, 0 );

    auto optionIt = new QRadioButton( "It" );
    grid->addWidget( optionIt, 3, 2 );

    auto optionTheMan = new QRadioButton( "The Man" );
    grid->addWidget( optionTheMan, 3, 4 );

    // Option with indented sub-option
    auto layoutOff = new QVBoxLayout;
    auto optionOff = new QRadioButton( "Off" );
    layoutOff->addWidget( optionOff );
    auto indentOff = new QHBoxLayout;
    auto indentOffSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentOff->addSpacerItem( indentOffSpacer );
    auto optionAndDie = new QRadioButton( "And Die" );
    indentOff->addWidget( optionAndDie );
    layoutOff->addLayout( indentOff );
    grid->addLayout( layoutOff, 4, 0 );

    // Option with indented sub-option
    auto layoutYou = new QVBoxLayout;
    auto optionYou = new QRadioButton( "You" );
    layoutYou->addWidget( optionYou );
    auto indentYou = new QHBoxLayout;
    auto indentYouSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentYou->addSpacerItem( indentYouSpacer );
    auto optionAndTheHorse = new QRadioButton( "And The Horse You Rode In On" );
    indentYou->addWidget( optionAndTheHorse );
    layoutYou->addLayout( indentYou );
    grid->addLayout( layoutYou, 4, 2 );

    // Custom option
    auto layoutCustom = new QHBoxLayout;
    auto optionCustom = new QRadioButton;
    layoutCustom->addWidget( optionCustom );
    auto customText = new QLineEdit;
    layoutCustom->addWidget( customText );
    grid->addLayout( layoutCustom, 4, 4 );

    auto centralWidget = new QWidget;
    centralWidget->setLayout( grid );

    this->setCentralWidget( centralWidget );
}

