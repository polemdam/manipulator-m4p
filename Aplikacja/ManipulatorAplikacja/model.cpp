#include "model.h"

float degToPi(float deg) { return deg * (M_PI/180); }

Model::Model(QWidget *parent) : QWidget(parent), x(0), y(0), z(0)
{
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    container->setMinimumSize(QSize(400, 400));
    view->defaultFrameGraph()->setClearColor(QColor(53, 53, 53));

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;


        // camera
        camera = view->camera();
        camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
        camera->setPosition(QVector3D(0, 0, 300.0f));
        camera->setViewCenter(QVector3D(0, 0, 0));

        // light
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor(QColor(255, 50, 50));
        light->setIntensity(2);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(180, 0, 0));
        lightEntity->addComponent(lightTransform);


        this->robot = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QSceneLoader *loader = new Qt3DRender::QSceneLoader(rootEntity);
        loader->setSource(QUrl("czlon1.obj"));
        this->robot->addComponent(loader);

        this->resetPosition();

        view->setRootEntity(rootEntity);
}

void Model::resetPosition() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->rotate(10, 150, 0);
}



void Model::rotate(float x, float y, float z) {
    auto *transform = new Qt3DCore::QTransform();
    this->x += degToPi(x);
    this->y += degToPi(y);
    this->z += degToPi(z);
    QVector3D offset(0, 0, 55);
    QMatrix4x4 matrix_x(1, 0, 0, offset[0], 0, cos(this->x), -sin(this->x), offset[1] , 0, sin(this->x), cos(this->x), offset[2], 0, 0, 0, 1);
    QMatrix4x4 matrix_y(cos(this->y), 0, sin(this->y), 0, 0, 1, 0, 0, -sin(this->y), 0, cos(this->y), 0, 0, 0, 0, 1);
    QMatrix4x4 matrix_z(cos(this->z), -sin(this->z), 0, 0, sin(this->z), cos(this->z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    QMatrix4x4 matrix = matrix_x * matrix_y * matrix_z;
    transform->setMatrix(matrix);
    this->robot->addComponent(transform);
}
