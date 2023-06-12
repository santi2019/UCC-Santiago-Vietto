package edu.ucc.arqSoft.service.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.ucc.arqSoft.service.dao.LocationDao;
import edu.ucc.arqSoft.service.dao.SensorDao;
import edu.ucc.arqSoft.service.dto.SensorRequestDto;
import edu.ucc.arqSoft.service.dto.SensorResponseDto;
import edu.ucc.arqSoft.service.model.Location;
import edu.ucc.arqSoft.service.model.Sensor;
import edu.ucc.arqSoft.service.model.Status;

@Service
@Transactional
public class SensorService {

	@Autowired
	private SensorDao sensorDao;
	
	@Autowired
	private LocationDao locationDao;

	public List<SensorResponseDto> getSensorsByLocation(Long locationId) {
		List<Sensor> sensors = sensorDao.getAll();
		List<SensorResponseDto> dtos = new ArrayList<SensorResponseDto>();
		
		SensorResponseDto dto;

		for (Sensor sensor : sensors) {
			dto = new SensorResponseDto();
			if (sensor.getStatus() == Status.ENCENDIDO && sensor.getLocation().getId() == locationId) {
				dto.setStatus(sensor.getStatus().toString());
				dto.setLocationName(sensor.getLocation().getName());
				dto.setId(sensor.getId());
				
				dtos.add(dto);
			}
		}
		
		return dtos;
	}

	public SensorResponseDto getSensorById(Long id) {

		Sensor sensor = sensorDao.load(id);

		SensorResponseDto dto = new SensorResponseDto();
		dto.setStatus(sensor.getStatus().toString());
		dto.setLocationName(sensor.getLocation().getName());
		dto.setId(id);
		
		return dto;

	}

	public SensorResponseDto registrar(SensorRequestDto dto) {
		Sensor sensor = new Sensor();
		Location responseLocation = null;
		List<Location> locations = locationDao.getAll();

		sensor.setStatus(Status.valueOf(dto.getStatus().toUpperCase())); 
		for (Location location : locations) {
			if(dto.getLocationName().toLowerCase() == location.getName().toLowerCase()) {
				responseLocation = location;
				break;
			}
		}
		sensor.setLocation(responseLocation);

		sensorDao.insert(sensor);
		
		SensorResponseDto response = new SensorResponseDto();
		response.setStatus(sensor.getStatus().toString());
		response.setLocationName(sensor.getLocation().getName());
		response.setId(sensor.getId());
		
		return response;
	}

	public SensorResponseDto toggle(Long id) {

		Sensor sensor = sensorDao.load(id);
		
		if (sensor.getStatus() == Status.APAGADO)
			sensor.setStatus(Status.ENCENDIDO);
		else
			sensor.setStatus(Status.APAGADO);
		
		//get sensor by id
		sensorDao.update(sensor);
		
		SensorResponseDto response = new SensorResponseDto();
		response.setStatus(sensor.getStatus().toString());
		response.setLocationName(sensor.getLocation().getName().toString());
		response.setId(sensor.getId());

		return response;
	}

	public List<SensorResponseDto> getSensors() {

		List<Sensor> sensors = sensorDao.getAll();
		
		List<SensorResponseDto> dtos = new ArrayList<SensorResponseDto>();
		
		SensorResponseDto dto;
		for (Sensor sensor : sensors) {
			dto = new SensorResponseDto();
			dto.setStatus(sensor.getStatus().toString());
			dto.setLocationName(sensor.getLocation().getName().toString());
			dto.setId(sensor.getId());
			
			dtos.add(dto);
		}
		
		return dtos;
	}


}