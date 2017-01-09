#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QButtonGroup>

#include "card.h"

Card::Card( QWidget* parent ) : QMainWindow( parent )
{
    // Create the top-level grid first
    auto vLayout = new QVBoxLayout;

    // Create the global switch
    auto optionWhatThe = new QCheckBox( "What The" );
    vLayout->addWidget( optionWhatThe );

    // Create the main text
    auto text = new QLabel( "FUCK" );
    vLayout->addWidget( text, 0, Qt::AlignCenter );

    // Create a grid for the rest of the buttons
    auto grid = new QGridLayout;

    // Create non-nested buttons
    auto optionMe = new QCheckBox( "Me" );
    grid->addWidget( optionMe, 1, 0 );

    auto optionThat = new QCheckBox( "That" );
    grid->addWidget( optionThat, 1, 1 );

    auto optionThis = new QCheckBox( "This" );
    grid->addWidget( optionThis, 1, 2 );

    auto optionYes = new QCheckBox( "Yes" );
    grid->addWidget( optionYes, 2, 0 );

    auto optionIt = new QCheckBox( "It" );
    grid->addWidget( optionIt, 2, 1 );

    auto optionTheMan = new QCheckBox( "The Man" );
    grid->addWidget( optionTheMan, 2, 2 );

    // Create nested options
    auto layoutOff = new QVBoxLayout;
    auto optionOff = new QCheckBox( "Off" );
    layoutOff->addWidget( optionOff );
    auto indentOff = new QHBoxLayout;
    auto indentOffSpacer = new QSpacerItem( 20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed );
    indentOff->addSpacerItem( indentOffSpacer );
    auto optionAndDie = new QCheckBox( "And Die" );
    indentOff->addWidget( optionAndDie );
    layoutOff->addLayout( indentOff );
    grid->addLayout( layoutOff, 3, 0 );

    // Suboption is disabled until parent option is enabled
    connect( optionOff, &QCheckBox::toggled, optionAndDie, &QCheckBox::setEnabled );
    optionAndDie->setEnabled( false );

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
    grid->addLayout( layoutYou, 3, 1 );

    // Suboption is disabled until parent option is enabled
    connect( optionYou, &QCheckBox::toggled, optionAndTheHorse, &QCheckBox::setEnabled );
    optionAndTheHorse->setEnabled( false );

    // Custom option
    auto layoutCustom = new QHBoxLayout;
    auto optionCustom = new QCheckBox;
    layoutCustom->addWidget( optionCustom );
    auto customText = new QLineEdit( "Everything" );
    layoutCustom->addWidget( customText );
    grid->addLayout( layoutCustom, 3, 2 );

    // Suboption is disabled until parent option is enabled
    connect( optionCustom, &QCheckBox::toggled, customText, &QLineEdit::setEnabled );
    customText->setEnabled( false );
    optionCustom->setFocusProxy( customText );

    // Put it all together
    auto optionsWidget = new QWidget;
    optionsWidget->setLayout( grid );
    vLayout->addWidget( optionsWidget );

    connect( optionWhatThe, &QCheckBox::toggled, optionsWidget, &QWidget::setDisabled );

    // Put it all together
    auto centralWidget = new QWidget;
    centralWidget->setLayout( vLayout );

    this->setCentralWidget( centralWidget );
}

