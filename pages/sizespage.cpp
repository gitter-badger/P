#include "sizespage.hpp"
#include "ui_sizespage.h"
#include "../modelingwizard.hpp"

SizesPage::SizesPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SizesPage)
{
    ui->setupUi(this);
    setTitle("Set sizes of the sensor");
}

SizesPage::~SizesPage()
{
    delete ui;
}

int SizesPage::nextId() const
{
    ModelingWizard * mw = dynamic_cast<ModelingWizard*>(wizard());
    mw->getDataRef().setDie_size(ui->die_size->value()*1e-3);
    mw->getDataRef().setMem_size(ui->mem_size->value()*1e-3);
    mw->getDataRef().setMem_thickness(ui->mem_thickness->value()*1e-6);    
    mw->getDataRef().setSpacer_height(ui->spacer_size->value()*1e-3);
    return ModelingWizard::MATERIAL_PAGE;
}
