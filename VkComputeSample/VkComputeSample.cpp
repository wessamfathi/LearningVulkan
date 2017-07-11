// VkComputeSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#define BAIL_ON_BAD_RESULT(result) \
if (VK_SUCCESS != (result)) { fprintf(stderr, "Failure at %u %s\n", __LINE__, __FILE__); return -1; }


int main()
{
	// create and initialize a VkInstance
	const VkApplicationInfo applicationInfo =
	{
		VK_STRUCTURE_TYPE_APPLICATION_INFO,
		0,
		"VkComputeSample",
		0,
		"",
		0,
		VK_MAKE_VERSION(1, 0, 9)
	};

	const VkInstanceCreateInfo instanceCreateInfo =
	{
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		0,
		0,
		&applicationInfo,
		0,
		0,
		0,
		0
	};

	VkInstance instance;
	BAIL_ON_BAD_RESULT(vkCreateInstance(&instanceCreateInfo, 0, &instance));

	// enumerate the available physical devices, first we get the number then we actually get the pointers to those devices
	uint32_t physicalDeviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, 0);

	VkPhysicalDevice* const physicalDevices = (VkPhysicalDevice*) malloc(sizeof(VkPhysicalDevice) * physicalDeviceCount);

	vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices);

	VkPhysicalDevice physicalDevice = physicalDevices[0];

	// determine the device's queue family to use with compute
	uint32_t queueFamilyPropertiesCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyPropertiesCount, 0);

	VkQueueFamilyProperties* const queueFamilyProperties = (VkQueueFamilyProperties*) malloc(sizeof(VkQueueFamilyProperties) * queueFamilyPropertiesCount);

	vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyPropertiesCount, queueFamilyProperties);

	// try to find a queue with just the transfer bit set
	for (uint32_t i = 0; i < queueFamilyPropertiesCount; ++i)
	{
	}

    return 0;
}

