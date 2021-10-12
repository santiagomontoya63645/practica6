#include "customview.h"

customview::customview(QWidget *parent): QGraphicsView(parent)
{

}

void customview::wheelEvent(QWheelEvent *event)
{
 setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
 double scalefactor=1.15;
 if(event->delta()>0){
     scale(scalefactor,scalefactor);

 }
 else{
     scale(1/scalefactor,1/scalefactor);
 }
}
