#ifndef VMAINWINDOW_H
#define VMAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QComboBox;
class VDirectoryTree;
class QSplitter;
class QListWidget;
class QTabWidget;
class QToolBar;
class VNote;
class VFileList;
class VTabWidget;
class QAction;
class QPushButton;
class VNotebook;
class QActionGroup;

class VMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    VMainWindow(QWidget *parent = 0);
    ~VMainWindow();

private slots:
    void setCurNotebookIndex(int index);
    // Create a notebook
    void onNewNotebookBtnClicked();
    void onDeleteNotebookBtnClicked();
    void onNotebookInfoBtnClicked();
    void updateNotebookComboBox(const QVector<VNotebook> &notebooks);
    void notebookComboBoxAdded(const QVector<VNotebook> &notebooks, int idx);
    void notebookComboBoxDeleted(const QVector<VNotebook> &notebooks, const QString &deletedName);
    void notebookComboBoxRenamed(const QVector<VNotebook> &notebooks,
                                 const QString &oldName, const QString &newName);
    void importNoteFromFile();
    void changeMarkdownConverter(QAction *action);
    void aboutMessage();

signals:
    void curNotebookChanged(const QString &notebookName);

private:
    void setupUI();
    void initActions();
    void initToolBar();
    void initMenuBar();
    bool isConflictWithExistingNotebooks(const QString &name);

    // If true, comboBox changes will not trigger any signal out
    bool notebookComboMuted;

    QLabel *notebookLabel;
    QLabel *directoryLabel;
    QComboBox *notebookComboBox;
    QPushButton *newNotebookBtn;
    QPushButton *deleteNotebookBtn;
    QPushButton *notebookInfoBtn;
    QPushButton *newRootDirBtn;
    QPushButton *deleteDirBtn;
    QPushButton *dirInfoBtn;
    VDirectoryTree *directoryTree;
    VFileList *fileList;
    VTabWidget *tabs;
    QSplitter *mainSplitter;
    VNote *vnote;

    // Actions
    QAction *editNoteAct;
    QAction *saveNoteAct;
    QAction *readNoteAct;
    QAction *importNoteAct;
    QActionGroup *converterAct;
    QAction *markedAct;
    QAction *hoedownAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif // VMAINWINDOW_H
