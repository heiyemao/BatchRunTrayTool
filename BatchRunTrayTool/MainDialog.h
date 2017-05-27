#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QHash>
#include <QSystemTrayIcon>
#include "ConstValue.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef QT_NO_SYSTEMTRAYICON
class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();
protected slots:
    void onActionTrigger(bool checked);
private:
    void initUI();
    void initConnect();

    QString findFilePath(const QString& path);
    QStringList listAllDirs(const QString& path);
    QIcon getPathLogo(const QString& path);
    QIcon getFileLogo(const QString& filename);
    QMenu* createMenu(const QString& path);
    bool isPropertyFile(const QString& dirname);
    QAction* createActionWithFolder(QMenu* menu, const QString& filename);
private:
    QSystemTrayIcon *m_trayIcon;
    QMenu *m_trayIconMenu;
    QHash<QAction*, SExecItem> m_actionHash;

};
//! [0]

#endif // QT_NO_SYSTEMTRAYICON

#endif // MAINDIALOG_H
