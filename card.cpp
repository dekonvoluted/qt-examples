#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
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
    indentWhatThe->addWidget( optionWhatThe );
    auto optionWhatThe = new QCheckBox( "What The" );

    grid->addLayout( indentWhatThe, 0, 0, 1, -1 );

    // Main text
    auto text = new QLabel( "F U C K" );
    grid->addWidget( text, 1, 0, 1, -1, Qt::AlignCenter );

    // Rest of the buttons
    grid->addWidget( optionMe, 2, 0 );
    auto optionMe = new QCheckBox( "Me" );

    auto optionThat = new QCheckBox( "That" );
    grid->addWidget( optionThat, 2, 2 );

    auto optionThis = new QCheckBox( "This" );
    grid->addWidget( optionThis, 2, 4 );

    auto optionYes = new QCheckBox( "Yes" );
    grid->addWidget( optionYes, 3, 0 );

    auto optionIt = new QCheckBox( "It" );
    grid->addWidget( optionIt, 3, 2 );

    auto optionTheMan = new QCheckBox( "The Man" );
    grid->addWidget( optionTheMan, 3, 4 );

    // Option with indented sub-option
    auto layoutOff = new QVBoxLayout;
    auto optionOff = new QCheckBox( "Off" );
    layoutOff->addWidget( optionOff );
    auto indentOff = new QHBoxLayout;
    auto indentOffSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentOff->addSpacerItem( indentOffSpacer );
    auto optionAndDie = new QCheckBox( "And Die" );
    indentOff->addWidget( optionAndDie );
    layoutOff->addLayout( indentOff );
    grid->addLayout( layoutOff, 4, 0 );

    // Option with indented sub-option
    auto layoutYou = new QVBoxLayout;
    auto optionYou = new QCheckBox( "You" );
    layoutYou->addWidget( optionYou );
    auto indentYou = new QHBoxLayout;
    auto indentYouSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentYou->addSpacerItem( indentYouSpacer );
    auto optionAndTheHorse = new QCheckBox( "And The Horse You Rode In On" );
    indentYou->addWidget( optionAndTheHorse );
    layoutYou->addLayout( indentYou );
    grid->addLayout( layoutYou, 4, 2 );

    // Custom option
    auto layoutCustom = new QHBoxLayout;
    auto optionCustom = new QCheckBox;
    layoutCustom->addWidget( optionCustom );
    auto customText = new QLineEdit;
    layoutCustom->addWidget( customText );
    grid->addLayout( layoutCustom, 4, 4 );
    optionCustom->setFocusProxy( customText );

    auto centralWidget = new QWidget;
    centralWidget->setLayout( grid );

    this->setCentralWidget( centralWidget );
}

