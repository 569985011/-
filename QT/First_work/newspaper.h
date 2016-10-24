#ifndef NEWSPAPER_H
#define NEWSPAPER_H

class Bewspaper : public Object
{
   Q_OBJECT

public:
    Newspaper(const QString &name):t_name(name){}
    send(){
        emit newPaper(t_name);
    }
signals:
    newPaper(const QString &name)const;
private:
    QString t_name;
}
#endif // NEWSPAPER_H
