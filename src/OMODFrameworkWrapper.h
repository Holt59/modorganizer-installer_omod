#pragma once

#include <QCoreApplication>

#include <iplugininstaller.h>

// Avoid tempting fate by avoiding letting MOC and C++/CLI see the same files
class OMODFrameworkWrapper
{
  Q_DECLARE_TR_FUNCTIONS(OMODFrameworkWrapper)

public:
  using EInstallResult = MOBase::IPluginInstaller::EInstallResult;

  OMODFrameworkWrapper(MOBase::IOrganizer* organizer, QWidget* parentWidget);

  EInstallResult install(MOBase::GuessedValue<QString>& modName, QString gameName, const QString& archiveName, const QString& version, int nexusID);

protected:
  void initFrameworkSettings(const QString& tempPath);

private:
  MOBase::IOrganizer* mMoInfo;
  QWidget* mParentWidget;
};
