#include "Collisionable.h"

bool Collisionable::Collision(Collisionable& objeto) const
{
    return getBounds().intersects(objeto.getBounds());
}

/*Propiedad de que se heredará a las clases que sus objetos deban
colisionar con objetos de otras clases.*/   