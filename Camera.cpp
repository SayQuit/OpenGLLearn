#include "Camera.h"
Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup) {
	this->Position = position;
	this->WorldUp = worldup;

	this->Forward = glm::normalize(target - position);
	this->Right = glm::normalize(glm::cross(this->Forward, this->WorldUp));
	this->Up= glm::normalize(glm::cross(this->Forward, this->Right));




}
Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup) {
	this->Position = position;
	this->WorldUp = worldup;


	this->Pitch = pitch;
	this->Yaw = yaw;

	this->Forward.x = glm::cos(pitch) * glm::sin(yaw);
	this->Forward.y = glm::sin(pitch);
	this->Forward.z = glm::cos(pitch) * glm::cos(yaw);

	this->Right = glm::normalize(glm::cross(this->Forward, this->WorldUp));
	this->Up = glm::normalize(glm::cross(this->Forward, this->Right));


}



Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(this->Position, this->Position + this->Forward, this->WorldUp);
}

void Camera::UpdateCameraVectors() {
	this->Forward.x = glm::cos(this->Pitch) * glm::sin(this->Yaw);
	this->Forward.y = glm::sin(this->Pitch);
	this->Forward.z = glm::cos(this->Pitch) * glm::cos(this->Yaw);

	this->Right = glm::normalize(glm::cross(this->Forward, this->WorldUp));
	this->Up = glm::normalize(glm::cross(this->Forward, this->Right));
}

void Camera::ProcessMouseMovement(float deltaX, float deltaY) {
	this->Pitch -= deltaY * this->SenseY;
	this->Yaw -= deltaX * this->SenseX;
	this->UpdateCameraVectors();

}

void Camera::UpdateCameraPos() {
	this->Position += this->Forward *this->speedZ * 0.001f;
}